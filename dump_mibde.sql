--
-- PostgreSQL database dump
--

-- Dumped from database version 15.1 (Ubuntu 15.1-1.pgdg22.04+1)
-- Dumped by pg_dump version 15.1 (Ubuntu 15.1-1.pgdg22.04+1)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: article; Type: TABLE; Schema: public; Owner: -
--

CREATE TABLE public.article (
    typea character(60) NOT NULL
);


--
-- Name: contenu_vente; Type: TABLE; Schema: public; Owner: -
--

CREATE TABLE public.contenu_vente (
    nom_snack character(60) NOT NULL,
    date_et_heure timestamp without time zone NOT NULL,
    occurrence integer,
    prix double precision DEFAULT 0.0 NOT NULL,
    prix_achat double precision DEFAULT 0.0 NOT NULL
);


--
-- Name: historique_vente; Type: TABLE; Schema: public; Owner: -
--

CREATE TABLE public.historique_vente (
    date_et_heure timestamp without time zone DEFAULT CURRENT_TIMESTAMP NOT NULL
);


--
-- Name: personne; Type: TABLE; Schema: public; Owner: -
--

CREATE TABLE public.personne (
    nom character varying NOT NULL,
    prenom character varying NOT NULL,
    actif integer DEFAULT 1 NOT NULL
);


--
-- Name: peut_contenir; Type: TABLE; Schema: public; Owner: -
--

CREATE TABLE public.peut_contenir (
    categorie character(60) NOT NULL,
    nom_snack character varying(100) NOT NULL
);


--
-- Name: snack; Type: TABLE; Schema: public; Owner: -
--

CREATE TABLE public.snack (
    nom_snack character varying(100) NOT NULL,
    prix double precision NOT NULL,
    prix_achat double precision NOT NULL,
    description character varying,
    quantite integer NOT NULL,
    en_vente integer DEFAULT 1 NOT NULL,
    rupture integer NOT NULL,
    typea character(60) NOT NULL,
    chemin_vers_limage character varying NOT NULL
);


--
-- Name: statut; Type: TABLE; Schema: public; Owner: -
--

CREATE TABLE public.statut (
    categorie character(60) NOT NULL
);


--
-- Name: vendu_par; Type: TABLE; Schema: public; Owner: -
--

CREATE TABLE public.vendu_par (
    date_et_heure timestamp without time zone NOT NULL,
    nom character varying NOT NULL,
    prenom character varying NOT NULL
);


--
-- Data for Name: article; Type: TABLE DATA; Schema: public; Owner: -
--

INSERT INTO public.article VALUES ('boisson                                                     ');
INSERT INTO public.article VALUES ('snack                                                       ');
INSERT INTO public.article VALUES ('nouille                                                     ');
INSERT INTO public.article VALUES ('autre                                                       ');


--
-- Data for Name: contenu_vente; Type: TABLE DATA; Schema: public; Owner: -
--

INSERT INTO public.contenu_vente VALUES ('cafer                                                       ', '2023-06-26 13:20:20.096639', 1, 0, 0);
INSERT INTO public.contenu_vente VALUES ('Caprisun                                                    ', '2023-06-26 13:20:20.096639', 1, 0, 0);
INSERT INTO public.contenu_vente VALUES ('Bounty                                                      ', '2023-06-26 13:20:20.096639', 2, 0, 0);
INSERT INTO public.contenu_vente VALUES ('cafer                                                       ', '2023-07-03 22:26:35.384863', 3, 0, 0);
INSERT INTO public.contenu_vente VALUES ('Bounty                                                      ', '2023-07-03 22:26:35.384863', 1, 0, 0);
INSERT INTO public.contenu_vente VALUES ('Caprisun                                                    ', '2023-07-03 22:26:35.384863', 2, 0, 0);
INSERT INTO public.contenu_vente VALUES ('cafer                                                       ', '2023-07-04 19:49:17.730763', 1, 0, 0);
INSERT INTO public.contenu_vente VALUES ('Bounty                                                      ', '2023-07-04 19:49:17.730763', 1, 0, 0);
INSERT INTO public.contenu_vente VALUES ('Caprisun                                                    ', '2023-07-04 19:49:17.730763', 1, 0, 0);
INSERT INTO public.contenu_vente VALUES ('cafer                                                       ', '2023-07-04 19:50:17.597879', 17, 0, 0);
INSERT INTO public.contenu_vente VALUES ('cafer                                                       ', '2023-07-06 20:47:33.781977', 2, 0, 0);
INSERT INTO public.contenu_vente VALUES ('Bounty                                                      ', '2023-07-06 20:47:33.781977', 1, 0, 0);
INSERT INTO public.contenu_vente VALUES ('Caprisun                                                    ', '2023-07-06 20:47:33.781977', 3, 0, 0);
INSERT INTO public.contenu_vente VALUES ('cafer                                                       ', '2023-07-06 20:47:55.140205', 1, 0, 0);
INSERT INTO public.contenu_vente VALUES ('Bounty                                                      ', '2023-07-06 20:47:55.140205', 3, 0, 0);
INSERT INTO public.contenu_vente VALUES ('Caprisun                                                    ', '2023-07-06 20:47:55.140205', 2, 0, 0);
INSERT INTO public.contenu_vente VALUES ('cafer                                                       ', '2023-07-12 11:58:35.856508', 3, 0, 0);
INSERT INTO public.contenu_vente VALUES ('Bounty                                                      ', '2023-07-12 11:58:35.856508', 2, 0, 0);
INSERT INTO public.contenu_vente VALUES ('Caprisun                                                    ', '2023-07-12 11:58:35.856508', 5, 0, 0);
INSERT INTO public.contenu_vente VALUES ('Bounty                                                      ', '2023-07-12 12:07:43.78548', 5, 0, 0);
INSERT INTO public.contenu_vente VALUES ('cafer                                                       ', '2023-07-12 17:36:34.11072', 2, 0, 0);
INSERT INTO public.contenu_vente VALUES ('Bounty                                                      ', '2023-07-12 17:36:34.11072', 2, 0, 0);
INSERT INTO public.contenu_vente VALUES ('test                                                        ', '2023-07-12 18:30:20.527688', 3, 0, 0);
INSERT INTO public.contenu_vente VALUES ('test                                                        ', '2023-07-14 13:36:29.548285', 1, 0, 0);
INSERT INTO public.contenu_vente VALUES ('Caprisun                                                    ', '2023-07-14 13:36:29.548285', 3, 0, 0);
INSERT INTO public.contenu_vente VALUES ('test                                                        ', '2023-07-15 13:51:14.938506', 1, 5, 2);
INSERT INTO public.contenu_vente VALUES ('Bounty                                                      ', '2023-07-15 13:51:14.938506', 2, 0.699999988079071, 0);
INSERT INTO public.contenu_vente VALUES ('Caprisun                                                    ', '2023-07-15 13:51:14.938506', 1, 0.4000000059604645, 0);
INSERT INTO public.contenu_vente VALUES ('Bounty                                                      ', '2023-07-15 13:52:54.814124', 2, 0.699999988079071, 0);
INSERT INTO public.contenu_vente VALUES ('cafer                                                       ', '2023-07-19 15:13:39.039877', 1, 0.5, 0);
INSERT INTO public.contenu_vente VALUES ('Caprisun                                                    ', '2023-07-19 15:13:39.039877', 1, 0.4000000059604645, 0);
INSERT INTO public.contenu_vente VALUES ('Bounty                                                      ', '2023-07-19 15:13:39.039877', 1, 0.699999988079071, 0);
INSERT INTO public.contenu_vente VALUES ('cafer                                                       ', '2023-07-19 22:00:26.632654', 1, 0.5, 0);
INSERT INTO public.contenu_vente VALUES ('Caprisun                                                    ', '2023-07-19 22:00:26.632654', 1, 0.4000000059604645, 0);
INSERT INTO public.contenu_vente VALUES ('Bounty                                                      ', '2023-07-19 22:00:26.632654', 2, 0.699999988079071, 0);
INSERT INTO public.contenu_vente VALUES ('Caprisun                                                    ', '2023-07-20 15:31:48.755115', 1, 0.4000000059604645, 0);
INSERT INTO public.contenu_vente VALUES ('Bounty                                                      ', '2023-07-20 15:31:48.755115', 1, 0.699999988079071, 0);
INSERT INTO public.contenu_vente VALUES ('cafer                                                       ', '2023-07-20 15:32:38.32502', 1, 0.5, 0);
INSERT INTO public.contenu_vente VALUES ('Bounty                                                      ', '2023-07-20 15:32:38.32502', 1, 0.699999988079071, 0);


--
-- Data for Name: historique_vente; Type: TABLE DATA; Schema: public; Owner: -
--

INSERT INTO public.historique_vente VALUES ('2023-06-26 13:20:20.096639');
INSERT INTO public.historique_vente VALUES ('2023-06-26 14:08:01.833625');
INSERT INTO public.historique_vente VALUES ('2023-06-27 09:26:13.09608');
INSERT INTO public.historique_vente VALUES ('2023-06-27 09:26:18.067647');
INSERT INTO public.historique_vente VALUES ('2023-06-27 09:26:18.343315');
INSERT INTO public.historique_vente VALUES ('2023-06-27 09:26:18.539143');
INSERT INTO public.historique_vente VALUES ('2023-06-27 09:26:20.025236');
INSERT INTO public.historique_vente VALUES ('2023-06-27 09:26:20.258822');
INSERT INTO public.historique_vente VALUES ('2023-06-27 09:26:57.7476');
INSERT INTO public.historique_vente VALUES ('2023-06-27 09:26:57.969545');
INSERT INTO public.historique_vente VALUES ('2023-06-27 09:27:42.67737');
INSERT INTO public.historique_vente VALUES ('2023-07-03 22:26:35.384863');
INSERT INTO public.historique_vente VALUES ('2023-07-04 19:49:17.730763');
INSERT INTO public.historique_vente VALUES ('2023-07-04 19:50:17.597879');
INSERT INTO public.historique_vente VALUES ('2023-07-06 20:47:33.781977');
INSERT INTO public.historique_vente VALUES ('2023-07-06 20:47:55.140205');
INSERT INTO public.historique_vente VALUES ('2023-07-12 11:58:35.856508');
INSERT INTO public.historique_vente VALUES ('2023-07-12 12:07:43.78548');
INSERT INTO public.historique_vente VALUES ('2023-07-12 17:36:34.11072');
INSERT INTO public.historique_vente VALUES ('2023-07-12 18:30:20.527688');
INSERT INTO public.historique_vente VALUES ('2023-07-14 13:36:29.548285');
INSERT INTO public.historique_vente VALUES ('2023-07-15 13:51:14.938506');
INSERT INTO public.historique_vente VALUES ('2023-07-15 13:52:54.814124');
INSERT INTO public.historique_vente VALUES ('2023-07-19 15:13:39.039877');
INSERT INTO public.historique_vente VALUES ('2023-07-19 22:00:26.632654');
INSERT INTO public.historique_vente VALUES ('2023-07-20 15:31:48.755115');
INSERT INTO public.historique_vente VALUES ('2023-07-20 15:32:38.32502');


--
-- Data for Name: personne; Type: TABLE DATA; Schema: public; Owner: -
--

INSERT INTO public.personne VALUES ('Groc', 'Maxime', 1);
INSERT INTO public.personne VALUES ('Groc', 'Simon', 1);
INSERT INTO public.personne VALUES ('Groc', 'Ben', 1);
INSERT INTO public.personne VALUES ('Tio', 'Alix', 1);
INSERT INTO public.personne VALUES ('Mami', 'Suzi', 1);
INSERT INTO public.personne VALUES ('Mami', 'Lulu', 1);


--
-- Data for Name: peut_contenir; Type: TABLE DATA; Schema: public; Owner: -
--

INSERT INTO public.peut_contenir VALUES ('halal                                                       ', 'Bounty');
INSERT INTO public.peut_contenir VALUES ('casher                                                      ', 'Bounty');
INSERT INTO public.peut_contenir VALUES ('vegan                                                       ', 'Bounty');
INSERT INTO public.peut_contenir VALUES ('casher                                                      ', 'Caprisun');
INSERT INTO public.peut_contenir VALUES ('vegan                                                       ', 'Caprisun');
INSERT INTO public.peut_contenir VALUES ('recyclabe                                                   ', 'Caprisun');
INSERT INTO public.peut_contenir VALUES ('halal                                                       ', 'cafe');
INSERT INTO public.peut_contenir VALUES ('casher                                                      ', 'cafe');
INSERT INTO public.peut_contenir VALUES ('vegan                                                       ', 'cafe');
INSERT INTO public.peut_contenir VALUES ('vegetarien                                                  ', 'cafe');
INSERT INTO public.peut_contenir VALUES ('recyclabe                                                   ', 'cafe');
INSERT INTO public.peut_contenir VALUES ('halal                                                       ', 'test');
INSERT INTO public.peut_contenir VALUES ('casher                                                      ', 'test');
INSERT INTO public.peut_contenir VALUES ('vegan                                                       ', 'test');
INSERT INTO public.peut_contenir VALUES ('vegetarien                                                  ', 'test');
INSERT INTO public.peut_contenir VALUES ('recyclabe                                                   ', 'test');
INSERT INTO public.peut_contenir VALUES ('halal                                                       ', 'cafer');
INSERT INTO public.peut_contenir VALUES ('casher                                                      ', 'cafer');
INSERT INTO public.peut_contenir VALUES ('vegan                                                       ', 'cafer');


--
-- Data for Name: snack; Type: TABLE DATA; Schema: public; Owner: -
--

INSERT INTO public.snack VALUES ('cafe', 100, 0, 'cafer cher
', 2, -1, 2, 'boisson                                                     ', '/home/simongroc/Bureau/LogicielMIBDE/imageBoissons/Caprisun.png');
INSERT INTO public.snack VALUES ('cafer', 0.5, 0, 'coucou cafer', 260, 1, 50, 'boisson                                                     ', '/home/simongroc/Bureau/LogicielMIBDE/imageBoissons/cafer.png');
INSERT INTO public.snack VALUES ('test', 5, 2, 'test test test', 38, 1, 20, 'boisson                                                     ', '/home/simongroc/Bureau/LogicielMIBDE/imageBoissons/cafer.png');
INSERT INTO public.snack VALUES ('Bounty', 0.7, 0, 'coco', 112, 1, 30, 'snack                                                       ', '/home/simongroc/Bureau/LogicielMIBDE/imageSnack/Bounty.png');
INSERT INTO public.snack VALUES ('Caprisun', 0.4, 0, 'sunnnn', 135, 1, 30, 'snack                                                       ', '/home/simongroc/Bureau/LogicielMIBDE/imageBoissons/Caprisun.png');


--
-- Data for Name: statut; Type: TABLE DATA; Schema: public; Owner: -
--

INSERT INTO public.statut VALUES ('halal                                                       ');
INSERT INTO public.statut VALUES ('casher                                                      ');
INSERT INTO public.statut VALUES ('vegan                                                       ');
INSERT INTO public.statut VALUES ('vegetarien                                                  ');
INSERT INTO public.statut VALUES ('recyclabe                                                   ');


--
-- Data for Name: vendu_par; Type: TABLE DATA; Schema: public; Owner: -
--

INSERT INTO public.vendu_par VALUES ('2023-06-26 13:20:20.096639', 'Groc', 'Simon');
INSERT INTO public.vendu_par VALUES ('2023-07-03 22:26:35.384863', 'Groc', 'Maxime');
INSERT INTO public.vendu_par VALUES ('2023-07-03 22:26:35.384863', 'Groc', 'Simon');
INSERT INTO public.vendu_par VALUES ('2023-07-04 19:49:17.730763', 'Groc', 'Ben');
INSERT INTO public.vendu_par VALUES ('2023-07-04 19:49:17.730763', 'Mami', 'Suzi');
INSERT INTO public.vendu_par VALUES ('2023-07-04 19:50:17.597879', 'Groc', 'Ben');
INSERT INTO public.vendu_par VALUES ('2023-07-04 19:50:17.597879', 'Mami', 'Suzi');
INSERT INTO public.vendu_par VALUES ('2023-07-06 20:47:33.781977', 'Groc', 'Ben');
INSERT INTO public.vendu_par VALUES ('2023-07-06 20:47:55.140205', 'Groc', 'Ben');
INSERT INTO public.vendu_par VALUES ('2023-07-06 20:47:55.140205', 'Tio', 'Alix');
INSERT INTO public.vendu_par VALUES ('2023-07-06 20:47:55.140205', 'Mami', 'Suzi');
INSERT INTO public.vendu_par VALUES ('2023-07-06 20:47:55.140205', 'Mami', 'Lulu');
INSERT INTO public.vendu_par VALUES ('2023-07-12 11:58:35.856508', 'Groc', 'Maxime');
INSERT INTO public.vendu_par VALUES ('2023-07-12 11:58:35.856508', 'Groc', 'Simon');
INSERT INTO public.vendu_par VALUES ('2023-07-12 12:07:43.78548', 'Groc', 'Ben');
INSERT INTO public.vendu_par VALUES ('2023-07-12 17:36:34.11072', 'Tio', 'Alix');
INSERT INTO public.vendu_par VALUES ('2023-07-12 18:30:20.527688', 'Mami', 'Suzi');
INSERT INTO public.vendu_par VALUES ('2023-07-14 13:36:29.548285', 'Mami', 'Lulu');
INSERT INTO public.vendu_par VALUES ('2023-07-15 13:51:14.938506', 'Groc', 'Simon');
INSERT INTO public.vendu_par VALUES ('2023-07-15 13:51:14.938506', 'Tio', 'Alix');
INSERT INTO public.vendu_par VALUES ('2023-07-15 13:52:54.814124', 'Groc', 'Simon');
INSERT INTO public.vendu_par VALUES ('2023-07-15 13:52:54.814124', 'Tio', 'Alix');
INSERT INTO public.vendu_par VALUES ('2023-07-19 15:13:39.039877', 'Mami', 'Lulu');
INSERT INTO public.vendu_par VALUES ('2023-07-19 22:00:26.632654', 'Groc', 'Ben');
INSERT INTO public.vendu_par VALUES ('2023-07-19 22:00:26.632654', 'Tio', 'Alix');
INSERT INTO public.vendu_par VALUES ('2023-07-20 15:31:48.755115', 'Tio', 'Alix');
INSERT INTO public.vendu_par VALUES ('2023-07-20 15:32:38.32502', 'Tio', 'Alix');


--
-- Name: article article_pkey; Type: CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.article
    ADD CONSTRAINT article_pkey PRIMARY KEY (typea);


--
-- Name: contenu_vente contenu_vente_pkey; Type: CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.contenu_vente
    ADD CONSTRAINT contenu_vente_pkey PRIMARY KEY (nom_snack, date_et_heure);


--
-- Name: historique_vente historique_vente_pkey; Type: CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.historique_vente
    ADD CONSTRAINT historique_vente_pkey PRIMARY KEY (date_et_heure);


--
-- Name: personne personne_pkey; Type: CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.personne
    ADD CONSTRAINT personne_pkey PRIMARY KEY (nom, prenom);


--
-- Name: peut_contenir peut_contenir_pkey; Type: CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.peut_contenir
    ADD CONSTRAINT peut_contenir_pkey PRIMARY KEY (categorie, nom_snack);


--
-- Name: snack snack_pkey; Type: CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.snack
    ADD CONSTRAINT snack_pkey PRIMARY KEY (nom_snack);


--
-- Name: statut statut_pkey; Type: CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.statut
    ADD CONSTRAINT statut_pkey PRIMARY KEY (categorie);


--
-- Name: vendu_par vendu_par_pkey; Type: CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.vendu_par
    ADD CONSTRAINT vendu_par_pkey PRIMARY KEY (date_et_heure, nom, prenom);


--
-- Name: contenu_vente contenu_vente_date_et_heure_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.contenu_vente
    ADD CONSTRAINT contenu_vente_date_et_heure_fkey FOREIGN KEY (date_et_heure) REFERENCES public.historique_vente(date_et_heure);


--
-- Name: contenu_vente contenu_vente_nom_snack_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.contenu_vente
    ADD CONSTRAINT contenu_vente_nom_snack_fkey FOREIGN KEY (nom_snack) REFERENCES public.snack(nom_snack);


--
-- Name: peut_contenir peut_contenir_categorie_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.peut_contenir
    ADD CONSTRAINT peut_contenir_categorie_fkey FOREIGN KEY (categorie) REFERENCES public.statut(categorie);


--
-- Name: peut_contenir peut_contenir_nom_snack_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.peut_contenir
    ADD CONSTRAINT peut_contenir_nom_snack_fkey FOREIGN KEY (nom_snack) REFERENCES public.snack(nom_snack);


--
-- Name: snack snack_typea_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.snack
    ADD CONSTRAINT snack_typea_fkey FOREIGN KEY (typea) REFERENCES public.article(typea);


--
-- Name: vendu_par vendu_par_date_et_heure_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.vendu_par
    ADD CONSTRAINT vendu_par_date_et_heure_fkey FOREIGN KEY (date_et_heure) REFERENCES public.historique_vente(date_et_heure);


--
-- Name: vendu_par vendu_par_nom_prenom_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY public.vendu_par
    ADD CONSTRAINT vendu_par_nom_prenom_fkey FOREIGN KEY (nom, prenom) REFERENCES public.personne(nom, prenom);


--
-- PostgreSQL database dump complete
--

